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
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    string s;
    cin >> s;
    vector<int> c(s.size(),0);

    int i=0;
    while(i<s.size()){
        if(s.at(i)=='R'){
            int f=1;
            while(s.at(i+f)!='L'){
                f++;
            }
            if(f%2==0) {
                c.at(i+f)+=f/2;
                c.at(i+f-1)+=f/2;
            }else{
                c.at(i+f-1)+=f/2+1;
                c.at(i+f)+=f/2;
            }
            i+=f;
        }else{
            int f=1;
            if(i<s.size()){
                while(i+f<s.size() && s.at(i+f)!='R'){
                    f++;
                }
            }
            if(f%2==0){
                c.at(i)+=f/2;
                c.at(i-1)+=f/2;
            }else{
                c.at(i)+=f/2+1;
                c.at(i-1)+=f/2;
            }
            i+=f;
        }

        //for(int i=0;i<s.size();i++) cout << c.at(i) << ' ';
        //cout << endl;
    }

    for(int i=0;i<s.size();i++) cout << c.at(i) << ' ';
    cout << endl;
}