#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n ;
    cin >> n;
    string ans = "";
    while(n){
        int rem = n%26;
        n/=26;
        if(rem == 0){
            ans+='z';
            n--;
        }
        else{
            char ch = 'a' + rem - 1;
            ans+=ch;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
 
}





