#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> T(n,"");
    vector<string> H(n,"");

    for(int i=0; i<n; ++i){
        cin >> T[i] >> H[i];
    }
    int t_score{0}, h_score{0};
    for(int i=0; i<n; ++i){
        if(T[i] < H[i]){
            h_score+=3;
        }
        else if(T[i] > H[i]){
            t_score+=3;
        }
        else{
            t_score+=1;
            h_score+=1;
        }
    }
    cout << t_score << ' ' << h_score << endl;
    return 0;
}
