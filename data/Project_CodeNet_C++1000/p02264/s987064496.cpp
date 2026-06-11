#include <iostream>
using namespace std;
#define LEN 100005

typedef struct Process { char name[100]; int time; } P;

P Q[LEN];
int head, tail;

void enqueue(P x) {
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue() {
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int min(int a, int b) { return a < b ? a : b; }

int main() {

    int n, q;
    cin >> n >> q;

    head = 1;
    tail = 1;

    for (int i = 0; i < n; ++i) {
        P p;
        cin >> p.name >> p.time;
        enqueue(p);
    }

    P user;
    int total = 0;
    while (head != tail) {
        user = dequeue();
        int cost = 0;
        cost = min(q, user.time);
        user.time -= cost;
        total += cost;
        if (0 < user.time)
            enqueue(user);
        else
            cout << user.name << " " << total << endl;
    }

    return 0;
}