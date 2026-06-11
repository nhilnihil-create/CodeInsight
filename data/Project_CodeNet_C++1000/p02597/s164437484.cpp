#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;

    int w=0,r=0;
    for(int i=0;i<n;i++){
        if(s.at(i)=='W') {
            w++;
        }else{
            r++;
        }
    }
    
    int wr=0;
    if(w<=r){
        for(int i=0;i<w;i++){
            if(s.at(n-1-i)=='W') wr++;
        }
        cout << w-wr << endl;
    }else{
        for(int i=0;i<r;i++){
            if(s.at(i)=='R') wr++;
        }
        cout << r-wr << endl;
    }
}