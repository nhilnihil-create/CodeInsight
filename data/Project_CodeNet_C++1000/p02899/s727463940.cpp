#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)

#include <string>
#include <vector>
#include <algorithm>
int main(){
    int n,a; cin >> n;
    vector<int> Jun(n+1);
    for(int i=1; i<=n ;i++){
        cin >> a;
        Jun[a] = i;
    }
    for(int i=1; i<=n; i++) printf("%d ",Jun[i]);
    printf("\n");
}