#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int House[4][3][10] = {0};
    // vector<int> House[4][3][10];
    int b, f, r,v;
    for (b = 0; b<4; b++ ){
        for (f = 0; f<3;f++){
            for (r = 0; r<10; r++){
                House[b][f][r]=0;
            }
        }
    }
    for (int l=0; l<n; l++){
        cin >> b >> f >> r >> v;
        House[b-1][f-1][r-1]+=v;
    }

    for (b = 0; b<4; b++ ){
        for (f = 0; f<3;f++){
            for (r = 0; r<10; r++){
                cout << " "<<House[b][f][r];
            }
            cout<< endl;
        }
        if (b !=3){
            cout << "####################" << endl;
        }

    }

}
