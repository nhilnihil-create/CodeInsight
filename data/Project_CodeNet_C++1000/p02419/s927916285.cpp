#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
 
#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;
 
using namespace std;
 
int main() {
    string w;
    string in;
    int i = 0;
    cin >> w;
    transform(w.begin(), w.end(), w.begin(), ::tolower);
    while(1){
        cin >> in;
        if(in == "END_OF_TEXT")
            break;
        transform(in.begin(), in.end(), in.begin(), ::tolower);
        int period = in.find('.', 0);
        int excramation = in.find('!', 0);
        int comma = in.find(',', 0);
        int mark = in.find('\"', 0);
        int question = in.find("?", 0);
        if (period != string::npos)
            in.erase(period);
        if (excramation != string::npos)
            in.erase(excramation);
        if (comma != string::npos)
            in.erase(comma);
        if (question != string::npos)
            in.erase(question);
        while (mark != string::npos) {
            in.erase(mark, 1);
            mark = in.find('\"', 0);
        }
 
 
//        cout << w << " " << in << endl;
        if(in == w)
            i++;
    }
    cout << i << endl;
 
    return 0;
}