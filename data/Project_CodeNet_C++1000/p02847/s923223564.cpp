#include <vector>
#include <string>
#include <cstdio>

using namespace std;

string inputWord() {
    char buf[256];
    scanf("%s", buf);
    return buf;
}

string S;
vector<string> X;

int main() {
    S = inputWord();
    X = vector<string>({"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"});
    for(int i=0; i<X.size(); ++i) if(X[i]==S) {
        printf("%d\n", 7-i);
    }
    return 0;
}
