#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int n,c=0;
  	cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
      	cin >> a[i];
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
        if(a[i]==a[j])
          	continue;
        else
          for(int k=j+1;k<n;k++)
            if(a[i]!=a[k] && a[j]!=a[k])
              if((a[i]+a[j]>a[k])&&(a[i]+a[k]>a[j])&&(a[j]+a[k]>a[i]))
                c++;
      }
    cout << c; 
    return 0;
}