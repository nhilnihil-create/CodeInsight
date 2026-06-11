#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
vector<int> cnt(100);
int Mketa;

void initCnt (int n) {
  for (int i = 1; i < 100; i++)
  {
    if (i % 10 == 0) continue;
    if (i / 10 == i % 10) {
      cnt[i] = cnt[i % 10];
      cerr << "cnt[" << i << "]=" << cnt[i] << endl;
      continue;
    }
    
    if (i < 10) cnt[i]++;

    int keta = 2;
    while (keta < Mketa) {
      if (keta == 2) {
        cnt[i]++;
        keta++;
        continue;
      }
      int temp = keta - 2;
      int ck = 1;
      while (temp--) {
        ck *= 10;
      }
      cnt[i] += ck;
      keta++;
    }
    int now = i % 10;
    int Mnow = now + 1;
    int ketatemp = keta - 1;
    while (ketatemp--)
    {
      now *= 10;
      Mnow *= 10;
    }
    if (i < 10) now += i;
    else now += i / 10;
    while (now <= min(n, Mnow))
    {
      cnt[i]++;
      if (Mketa == 2) break;
      now += 10;
    }
    cerr << "cnt[" << i << "]=" << cnt[i] << endl;
  }
  
}

int main() {
  int N;
  cin >> N;
  Mketa = 1;
  int temp = N;
  while (temp / 10 > 0) {
    Mketa++;
    temp /= 10;
  }
  cerr << "Mketa=" << Mketa << endl;
  int ans = 0;

  initCnt(N);
  for (int i = 1; i <= N; i++) {
    if (i % 10 == 0) continue;

    int keta = 1;
    int j = i;
    while (j / 10 > 0) {
      keta++;
      j /= 10;
    }
    if (keta > 2) {
      int two = j * 10 + (i % 10);
      ans += cnt[two];
    } else {
      ans += cnt[i];
    }
  }
  
  cout << ans << endl;
  return 0;
}