    #include <bits/stdc++.h>
    using namespace std;
    int main(void){
      int n,i,j,a[1010][1010],t=-1,k[1010]={};
      bool d[1010],pos=true;
      cin >> n;
      for (i=1;i<=n;i++) for (j=0;j<n-1;j++) cin >> a[i][j];
      while (pos){
        t++;
        pos=false;
        for (i=1;i<=n;i++) d[i]=false;
        for (i=1;i<=n;i++) if (k[i]!=n-1){
          j=a[i][k[i]];
          if (!d[i] && !d[j] && a[j][k[j]]==i){
            pos=true;
            k[i]++;
            k[j]++;
            d[i]=true;
            d[j]=true;
          }
        }
      }
      for (i=1;i<=n;i++) if (k[i]!=n-1) break;
      if (i==n+1) cout << t << endl;
      else cout << -1 << endl;
      return 0;
    }