#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);


bool isPalindrome(string s) {
    int upper,lower,len;
    len=s.length();

    if(len==1) {
        return true;
    }

    if(len%2==0) {
        lower=(len/2)-1;
        upper=lower+1;
    }
    else {
        int mid=len/2;
        lower=mid-1;
        upper=mid+1;
    }

    while(s[lower]==s[upper]&&lower>0&&upper<len) {
        upper++;
        lower--;
    }

    if(upper==len-1&&lower==0&&(s[upper]==s[lower])) {
        return true;
    }
    else {
        //cout<<"this the the len: "<<len<<endl;
        //cout<<"this is upper "<<upper<<endl;
        //cout<<"this is lower "<<lower<<endl;

        return false;
    }

}
int main() {
    fast_io;

    string s;
    cin>>s;
    int len=s.length();

    int pt1=((len-1)/2);
    int pt2=((len+3)/2)-1;
   // cout<<"pt1: "<<pt1<<endl;
   // cout<<"pt2: "<<pt2<<endl;
    //cout<<s.substr(0,pt1)<<endl;
    //cout<<s.substr(pt2, len-pt2)<<endl;
    if(isPalindrome(s)&&isPalindrome(s.substr(0,pt1))&&isPalindrome(s.substr(pt2, len-pt2))) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }


}


