#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int64_t r=0;
    int64_t g=0;
    int64_t b=0;
    for(int i=0; i<s.size(); i++){
        if(s.at(i) == 'R') r++;
        else if(s.at(i) == 'G') g++;
        else b++;
    }
    int64_t minus=0;
    for(int i=0; i<s.size()-2; i++){
        for(int j=1; i+2*j<s.size(); j++){
            if(s.at(i)!=s.at(i+j) && s.at(i+j)!=s.at(i+2*j) && s.at(i)!=s.at(i+2*j)){
                minus++;
            }
        }
    }
    cout << r*g*b - minus << endl;
}
