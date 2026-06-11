#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    string head_s;
    string tail_s = s;
    rep(i, q){
        int a;
        cin >> a;
        if(a == 1){
            swap(head_s, tail_s);
        }else{
            int f;
            char c;
            cin >> f >> c;
            if(f == 1) head_s.push_back(c);
            else tail_s.push_back(c);
        }
    }
    reverse(head_s.begin(), head_s.end());
    s = head_s + tail_s;
    cout << s << endl;
    return 0;
}