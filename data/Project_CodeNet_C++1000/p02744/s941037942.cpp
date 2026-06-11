#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;

int main() {
    cin >> n;
    vector< vector<string> > ansvec(10, vector<string>());
    ansvec.at(0).emplace_back("a");
    if(n == 1) cout << "a" << endl;
    else {
        for(int i = 1; i < n; ++i) {
            int veclen = ansvec.at(i-1).size();
            for(int j = 0; j < veclen; ++j) {
                string check = ansvec.at(i-1).at(j);
                int chlen = check.length();
                int alp = 0;
                for(int k = 0; k < chlen; ++k) {
                    int cha = (int)(check.at(k));
                    chmax(alp, cha);
                }

                for(int k = 97; k <= alp+1; ++k) {
                    string ansc = check + (char)k;
                    ansvec.at(i).emplace_back(ansc);
                }
            }
        }

        for(int i = 0; i < (int)ansvec.at(n-1).size(); ++i) {
            cout << ansvec.at(n-1).at(i) << endl;
        }
    }
}