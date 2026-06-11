#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
int n;
cin >> n;
int n2 = 1 << n;
vector<int> s(n2);
rep(i,n2){
    cin >> s[i];
}
vector<int> a;

sort(s.begin(),s.end());
a.push_back(s.back());
s.back() = -1;


rep(i,n) {
    vector<int> p = a;
    sort(p.begin(),p.end());
    int idx = n2-1;

    while(p.size() >0 && idx >= 0){
        if(s[idx] == -1){
            idx--;
            continue;
        }
        if(s[idx] < p.back()){
            a.push_back(s[idx]);
            p.pop_back();
            s[idx] = -1;
        }
        idx--;
    }
    if(p.size() > 0){
        puts("No");
        return 0;
    }
}

puts("Yes");
return 0;

}