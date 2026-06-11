#include<bits/stdc++.h>
using namespace std;
int main(){
        long long n; cin>>n; string str="";
        while(n){
                int rem=n%26;
                if(!rem) str='z'+str;
                else str=(char)(97+rem-1)+str;
                n/=26;
                if(!rem) n--;
        }
        cout<<str<<endl;
}
