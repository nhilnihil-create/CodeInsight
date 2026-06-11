#include <iostream>
using namespace std;

#include <string>
#include <vector>
int main(){
    int n,k; cin >> n >> k;
    int d,a;
    vector<int> nusuke(n);
    while(k--){
        cin >> d;
        while(d--){
            cin >> a;
            nusuke[a-1]++;
        }
    }
    int ans=0;
    for(int &i:nusuke) if(i==0) ans++;
    cout << ans << endl;
}