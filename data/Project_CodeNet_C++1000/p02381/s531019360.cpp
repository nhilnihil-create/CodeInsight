#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<vector<int> > vec1;
    vector<int> vec2;
    vector<vector<int> >::iterator it;
    int i, n;
    double x, ave, sd;

    while(1) {
        cin >> n;
        if(n == 0) break;
        vec2.clear();
        for(i=0; i<n; ++i) {
            cin >> x;
            vec2.push_back(x);
        }
        vec1.push_back(vec2);
    }

    cout << fixed;
    cout.precision(4);
    for(it=vec1.begin(); it!=vec1.end(); ++it) {
        ave = 0;
        for(i=0; i<(*it).size(); ++i) {
            ave += (*it)[i];
        }
        ave /= (*it).size();
        sd = 0;
        for(i=0; i<(*it).size(); ++i) {
            sd += (((*it)[i] - ave) * ((*it)[i] - ave));
        }
        sd /= (*it).size();
        sd = sqrt(sd);
        cout << sd << endl;
    }

    return 0;
}