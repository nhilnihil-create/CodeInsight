#include <bits/stdc++.h>
using namespace std;



int main() {
    long long int n;
    cin>>n;
    if(n==0){
        cout <<0 << endl;
        return 0;
    }
    long long int count=0;
    if(n%2==1){
        cout <<0 << endl;
        return 0;
    }
    else{
        n/=10;
        count+=n;
        while(n>0){
            n/=5;
            count+=n;
        }
    }
    cout << count << endl;



    return 0;    
}
