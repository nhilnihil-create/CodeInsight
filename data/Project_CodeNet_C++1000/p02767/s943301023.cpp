#include<iostream>

using namespace std;

int main(){
    int n;
    int home[110];
    cin >> n;
    for(int i=0;i < n;i++){
        cin >> home[i];
    }
    int ans = 10000000;
    for(int p=1;p <= 100;p++){
        int vit = 0;
        for(int i=0;i < n;i++){
            vit += (p-home[i])*(p-home[i]);
        }
        ans = min(ans,vit);
    }
    cout << ans << endl;
    return 0;
}