#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    string str;
    int len;
}Music;

int main(int, char**) {
    int N;
    vector<Music> playList;

    cin >> N;
    playList.reserve(N);

    for(int i=0;i<N;++i){
        Music m;
        cin >> m.str >> m.len;
        playList.emplace_back(m);
    }

    string last;
    cin >> last;

    auto it = begin(playList);
    for(;it!=end(playList)&&it->str!=last;++it);
    int sum = 0;
    for(++it;it!=end(playList);++it){
        sum += it->len;
    }
    cout << sum << "\n";
}
