#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p;
    int num=200010;
    int count=0;
    for(int i=0; i<n; i++){
        cin >> p;
        if(p<=num){
            count++;
            num=min(num,p);
        }
    }
    cout << count << endl;
}