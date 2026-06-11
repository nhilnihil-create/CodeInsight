#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string s, int n){
    int i = 0;
    int j = n-1;
    while (i < j){
        if (s[i] != s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(){
    string s;
    cin>>s;
    int n = (int) s.length();
    int a = (n - 1)/2;
    int b = (n + 3)/2;
    string s1 = "";
    string s2 = "";
    for (int i = 0; i<a; i++){
        s1+=s[i];
    }
    for (int i = b-1; i<n; i++){
        s2+=s[i];
    }
    if (check(s, n) && check(s1, a) && check(s2, n-b+1)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
