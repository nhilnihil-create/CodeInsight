#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    long long n;
    cin>>n;
    string s;
    while(n){
        n--;
        s+=char('a'+(n%26));
        n/=26;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}