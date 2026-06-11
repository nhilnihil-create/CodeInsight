#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdio>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
using namespace std;
#define INF 999999999

string s;

int suf[200100];
int freq[2300];

int main(){
    cin >> s;
    int mult = 1;
    int ans = 0;
    freq[0] = 1;
    for (int i = s.size()-1; i >= 0; i--){
        suf[i] = suf[i+1]+(s[i]-'0')*mult;
        suf[i]%=2019;
        mult *= 10;
        mult %= 2019;
        ans += freq[suf[i]];
        freq[suf[i]]++;
    }
    //for (int i = 0; i < s.size(); i++) printf("%d ", suf[i]);
    //cout << "\n";
    printf("%d", ans);
}
