#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, m, pin, ac = 0, wa = 0;
    cin >> n >> m;
    vector<vector<string>> p(n, vector<string>(0));
    vector<string> s(m);
    for(int i = 0; i < m; ++i){
        cin >> pin >> s.at(i);
        pin--;
        if(p.at(pin).size() == 0){
            if(s.at(i) == "WA") p.at(pin).push_back("WA");
            else{
                ac++;
                wa += p.at(pin).size();
                p.at(pin).push_back("AC");
            }  
        }
        else{
            if(p.at(pin).at(p.at(pin).size() - 1) == "AC") continue;
            else if(s.at(i) == "WA") p.at(pin).push_back("WA");
            else{
                ac++;
                wa += p.at(pin).size();
                p.at(pin).push_back("AC");
            }
        }
    }
    cout << ac << " " << wa << endl;
    return 0;
}