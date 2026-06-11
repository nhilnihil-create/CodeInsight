#include <iostream>
#include <vector>
using namespace std;

static const int A = 80;
static const int B = 65;
static const int C = 50;
static const int D = 30;

int main(void) {
    int tmpResult, M, F, R;
    vector<char> results;

    while(true) {
        cin >> M >> F >> R;
        if(M == -1 && F == -1 && R == -1) break;
        if(M == -1 || F == -1) {results.push_back('F'); continue;}

        tmpResult = M + F;
        if(tmpResult >= A) {results.push_back('A'); continue;}
        if(tmpResult >= B) {results.push_back('B'); continue;}
        if(tmpResult >= C) {results.push_back('C'); continue;}
        if(tmpResult >= D && R >= C) {results.push_back('C'); continue;}
        if(tmpResult >= D) {results.push_back('D'); continue;}
        results.push_back('F');
    }

    for(auto result: results)
        cout << result << endl;

    return 0;
}