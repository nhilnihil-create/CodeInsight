#include <iostream>
using namespace std;

#include <string>
int main(){
    int n; cin >> n;
    string str; cin >> str;
    long long r=0,g=0,b=0;
    for(int i=0; i<n; i++) {
        switch (str.at(i)){
            case 'R':
                r++;
                break;
            case 'G':
                g++;
                break;
            default:
                b++;
                break;
        }
    }
    long long ans = r*g*b;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            int k = 2*j-i;
            if(k>=n) continue;            
            if(str[i]!=str[j] && str[i]!=str[k] && str[j]!=str[k]) ans--;
        }
    }
    cout << ans << endl;
}