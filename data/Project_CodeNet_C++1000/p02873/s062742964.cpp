#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
using namespace std;


int main(void){
    string s = ">";
    cin >> s;
    vector <int>table(s.size()+1, 0);

    for(int cnt =0; cnt < 1000000; cnt++){
        int flag = 0;
        for(int i =0;i < s.size(); i++){
            if(s[i] == '<' && table[i] >= table[i+1]){
                table[i+1] = table[i] + 1;
                flag = 1;
            }
        }
        for(int i = s.size() -1 ; i >= 0; i-- ){
            if(s[i] == '>' && table[i] <= table[i+1]){
                table[i] = table[i+1] + 1;
                flag = 1;
            }
        }

        if(flag == 0) break;
    }
    
    long sum = accumulate(table.begin(), table.end(),0L);
    cout << sum << endl;
    return 0;
}   