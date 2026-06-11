#include <iostream>
#include <cassert>
// #include <queue>

#define INF 922337203685477580
#define N 1100000
typedef long long ll;

using namespace std;

struct Task {string task; int cost;};
struct Task queue[N];
int head = 0;
int tail = 0;

void enqueue(Task t) {
  queue[tail] = t;
  tail = (tail + 1) % N;
}
struct Task dequeue() {
  head = (head + 1) % N;
  return queue[head - 1];
}
int isEmpty () {
  return head == tail;
}


int main() {
  int n, q;
  cin >> n >> q;

  struct Task T[n];

  for (int i = 0; i < n; i++) {
    cin >> T[i].task >> T[i].cost;
  }
  for (int i = 0; i < n; i++) {
    enqueue(T[i]);
  }

  ll elapsed = 0L;

  while(!isEmpty()) {
    struct Task t = dequeue();
    if (t.cost > q) {
      struct Task newT = {t.task, t.cost - q};
      enqueue(newT);
      elapsed += q;
    } else {
      elapsed += t.cost;
      cout << t.task << " " << elapsed << endl;
    }
  }

  return 0;
}