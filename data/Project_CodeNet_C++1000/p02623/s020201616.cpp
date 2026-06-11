#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N, M, K;
  cin >> N >> M >> K;
  
  vector<int> A(N), B(M);
  
  vector<int> book(N + 1); //読める本の数 Aの本はN冊～0冊
  int64_t total = 0; //Aの本を〇冊読むのにかかる時間
  int64_t btotal = 0;
  int bbook = 0;
  int y = 0;
  int maxbook = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    total += A.at(i);
  }
  for(int i = 0; i < M; i++) cin >> B.at(i);
 
  for(int i = N; i >= 0; i--)
  {
    if(i != N) total -= A.at(i);
    if(total > K) continue;
    book.at(i) += i;
    while(total + btotal < K && y < M)
    {
      if(total + btotal + B.at(y) <= K)
      {
        btotal += B.at(y);
        y++;
        bbook++;
      }
      else break;
    }
    book.at(i) += bbook;
  }
  for(int i = 0; i <= N; i++)
  {
    if(maxbook < book.at(i)) maxbook = book.at(i);
  }  

  cout << maxbook << endl;
}