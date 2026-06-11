#include<bits/stdc++.h>
using namespace std;

int main(){
  
  while(1){
    int n=0;
    cin >> n;
    if(n==0)break;
    int time[1000000] = {};
    for(int i=0;i<1000000;i++){
      time[i] =0;

    }
    
    for(int i=0;i<n;i++){
      
      int h,m,s;
      char c;
      c =0;
      cin >> h >> c >> m >> c >> s;

      int a = h * 3600 + m * 60 + s;

      time[a]++;

      cin >> h >> c >> m >> c >> s;

      a = h * 3600 + m * 60 + s;

      time[a]--;
    }

    int cnt,mx;
    mx =0;
    cnt= 0;
    for(int i=0;i<1000000;i++){
      cnt += time[i];
      mx = max(mx,cnt);
    }
    cout << mx << endl;

  }




}

