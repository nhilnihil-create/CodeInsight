#include "bits/stdc++.h"
using namespace std;

const int maxn = 4005;

char s[maxn];
int p[maxn], p1[maxn], p2[maxn];

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  scanf("%s", s);

  for(int i = 0; i < n; ++i){
    if(s[i] == 'R'){
      p[i] = 1;
    }else if(s[i] == 'G'){
      p1[i] = 1;
    }else {
      p2[i] = 1;
    }
  }
  for(int i = 1; i < n; ++i){
    p[i] += p[i - 1]; p1[i] += p1[i - 1]; p2[i] += p2[i - 1];
  }
  long long ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      int dis = j - i;
      if(s[i] == 'R' && s[j] == 'G'){
        ans += p2[n - 1] - p2[j];
        if(j + dis < n){
          if(s[j + dis] == 'B')ans--;
        }
      }
      if(s[i] == 'R' && s[j] == 'B'){
        ans += p1[n - 1] - p1[j];
        if(j + dis < n){
          if(s[j + dis] == 'G')ans--;
        }
      }
      if(s[i] == 'B' && s[j] == 'R'){
        ans += p1[n - 1] - p1[j];
        if(j + dis < n){
          if(s[j + dis] == 'G')ans--;
        }
      }
      if(s[i] == 'G' && s[j] == 'R'){
        ans += p2[n - 1] - p2[j];
        if(j + dis < n){
          if(s[j + dis] == 'B')ans--;
        }
      }
      if(s[i] == 'G' && s[j] == 'B'){
        ans += p[n - 1] - p[j];
        if(j + dis < n){
          if(s[j + dis] == 'R'){
            ans--;
          }
        }
      }
      if(s[i] == 'B' && s[j] == 'G'){
        ans += p[n - 1] - p[j];
        if(j + dis < n){
          if(s[j + dis] == 'R')ans--;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}