#include <iostream>
#include <map>

using namespace std;

int main(){
    int N;
    cin >> N;
    string str;
    map<string,int> S;
    for(int i=0; i<N; i++){
        cin >> str;
        if (S.count(str)) S[str]++;
        else S[str]=1;
    }
    int max = 0;
    for(auto i=S.begin(); i!=S.end(); i++) {
        if(i->second > max) max = i->second;
    }
    for(auto i=S.begin(); i!=S.end(); i++) {
        if(max==i->second) cout << i->first << endl;
    }
    return 0;
}