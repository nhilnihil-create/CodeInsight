//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int h,w,a,b;
char arr[1005][1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>h>>w>>a>>b;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            arr[i][j]='0';
        }
    }
    for(int i=1;i<=b;i++){
        for(int j=1;j<=a;j++){
            arr[i][j]='1';
        }
    }
    for(int i=b+1;i<=h;i++){
        for(int j=a+1;j<=w;j++){
            arr[i][j]='1';
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}