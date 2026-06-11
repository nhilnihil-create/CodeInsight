#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<LL> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        if(a.at(i) == 0){
            cout << "0" << endl;
            return 0;
        }
    }
    
    LL mul =1;
    for(int i=0; i<n; i++){
        if(mul > 1000000000000000000/a.at(i)){
            cout << "-1" << endl;
            return 0;
        }
            mul *= a.at(i);
    }
    cout << mul << endl;  
    return 0;

}