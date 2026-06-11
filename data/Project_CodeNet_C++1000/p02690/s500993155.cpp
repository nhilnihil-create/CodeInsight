#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main(){
    int const k = 1000;
    int x;
    P p;
    cin >> x;
    for(int i = -k; i <k; i++){
        for(int j = -k; j <k; j++){
            if (pow(i,5) - pow(j,5) == x){
                p.first = i;
                p.second = j;
                break;
            }
            
        }
    }
    cout << p.first << " " << p.second << endl;
    
return 0;
}