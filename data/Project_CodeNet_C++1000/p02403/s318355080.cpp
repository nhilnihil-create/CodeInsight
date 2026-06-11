#include <iostream>
#include <vector>
int main(){
    using namespace std;
    int h,w,i,j,k;
    vector<int> v;
    h = 1;
    w = 1;
    while(h!=0||w!=0){
        cin >> h >> w;
        if(h==0&&w==0){
            break;
        }
        v.push_back(h);
        v.push_back(w);
    }
    int size = v.size();
    for(i=0;i<(size/2);i++){
        h = v[2*i];
        w = v[2*i+1];
        for(j=0;j<h;j++){
            for(k=0;k<w;k++){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}