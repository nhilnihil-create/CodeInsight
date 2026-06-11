#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    int count=0;
    for(int i=0; i<n-1; i++){
        if(s.at(i) != s.at(i+1)) count++;
    }
    cout << n-1-max(count-2*k, 0) << endl;
}
