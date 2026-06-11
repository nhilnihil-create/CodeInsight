#include <iostream>
#include <map>
#define ll long long
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int counter=0;
    int h[n],a[n];
    for(int i=1; i<=n; i++){
        cin >> h[i];
        a[i]=1;
    }
    for(int i=1 ;i<=m; i++){
        cin >> x;
        cin >> y;
        if(h[x]<=h[y]){
            a[x]=0;
        }
        if(h[y]<=h[x]){
            a[y]=0;
        }

    }
    for(int i=1; i<=n; i++){
        if(a[i]==1){
            counter++;
        }
    }
    cout << counter;
    return 0;
}
