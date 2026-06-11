#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[555][555];
void sv(int x, int y, int s){
    if(x==y)
        return;
    int m=(x+y)/2;
    for(int i=x; i<=m; ++i){
        for(int j=m+1; j<=y; ++j){
            a[i][j]=s;
        }
    }
    sv(x, m, s+1);
    sv(m+1, y, s+1);
}
int main(){
    int n;
    while(cin>>n){
        ll ans=0;
        sv(1, n, 1);
        for(int i=1; i<n; ++i){
            for(int j=i+1; j<=n; ++j){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
  return 0;
}


