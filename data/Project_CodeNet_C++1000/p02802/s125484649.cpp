#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(void){
    int n, m;
    cin >> n >> m;
    vi AC(n+1, 1), WA(n+1);
    int ac = 0, wa = 0;
    for(int i=0; i<m; i++){
        int p;
        string s;
        cin >> p >> s;
        if(AC[p] == 0) continue;
        if(s == "AC"){
            wa += WA[p]; ac++;
            AC[p] = 0;
        }
        if(s == "WA") WA[p]++;
    }
    cout << ac << ' ' << wa << '\n';
    return 0;
}