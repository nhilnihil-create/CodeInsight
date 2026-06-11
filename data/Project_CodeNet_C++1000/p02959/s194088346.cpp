#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, tmp;
    long long ans=0;
    scanf("%d",&n);
    vector<int>a(n+1);
    vector<int>b(n);
    for(int i=0; i<n+1; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        if(b[i]<=a[i]){
            ans += b[i];
        }else{
            ans += a[i];
            b[i] -= a[i];
            ans += min(b[i], a[i+1]);
            a[i+1] -= min(b[i],a[i+1]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
