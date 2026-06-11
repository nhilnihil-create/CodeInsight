#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n=0;
    cin>>s;
    while (!s.empty()){
        n+=int(s.back())-int('0');
        n=n%9;
        
        s.pop_back();
    }

    if (n==0){cout<< "Yes";}
    else {cout<<"No";}

    return 0;

}


        