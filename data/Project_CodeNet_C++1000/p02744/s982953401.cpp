#include <iostream>
#include <vector>

using namespace std;

void recur(int index, int num, vector<int>& vec){
    if(index==vec.size()){
        for(int v : vec){
            cout << (char)('a'+v);
        }
        cout << endl;
        return;
    }
    for(int i=0;i<num;++i){
        vec[index] = i;
        recur(index+1, num, vec);
    }
    vec[index] = num;
    recur(index+1, num+1, vec);
}
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    recur(0, 0, vec);

    return 0;
}