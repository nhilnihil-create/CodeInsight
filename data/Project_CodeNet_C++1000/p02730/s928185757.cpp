#include <bits/stdc++.h>
using namespace std;
string s;

bool palind(string x){
    auto size = x.size();
    for(int i=0; i<size/2; i++){
        if(x[i] != x[size-1-i]) return false;
    }
    return true;
}

bool check(){
    int length1 = (s.size()-1)/2;
    int length2 = s.size()-(s.size()+3)/2+1;
    return palind(s) && palind(s.substr(0,length1)) && palind(s.substr((s.size()+3)/2-1, length2));
}
int main(){
    cin >> s;
    if(check()) printf("Yes");
    else printf("No");
}