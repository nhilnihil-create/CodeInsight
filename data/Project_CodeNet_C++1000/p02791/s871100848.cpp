#include <bits/stdc++.h>
using namespace std;
#define MAX pow(10,18)
typedef long long ll;

int main(){
  
    int N,P,minv,ans=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> P;
        if(i == 0){ minv = P; ans++; }
        else { if(minv >= P) {minv = P; ans++;}}
    }
    cout << ans << endl;
}