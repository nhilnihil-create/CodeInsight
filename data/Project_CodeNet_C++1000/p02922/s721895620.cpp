#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // The minimum no. of powerstrips required for B or more empty sockets.
  int A, B, cnt, sockets;
  cin >> A >> B;
  sockets = 1;
  cnt = 0;

  // Every time we attach a socket, we occupy one empty socket.
  while(sockets < B) {
    sockets--; 
    sockets+=A;
    cnt++;
  }

  cout << cnt << '\n';
  return 0;
}

