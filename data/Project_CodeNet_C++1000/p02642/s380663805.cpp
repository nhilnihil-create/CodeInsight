#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int AMAX = 1000000;
int ans = 0;
map<int, int> arr;

int main(void)
{
    vector<bool> vec(AMAX, false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int k = 0; k < N; k++)
    {
        cin >> A[k];
        arr[A[k]] = arr[A[k]] + 1;
    }
    auto yakusuu = [&](int a, vector<int> &y) {
        int pw = sqrt(a);
        //cout << pw<<endl;
        y.push_back(1);
        for (int j = 2; j <= pw; j++)
        {
            if (a % j == 0)
            {
                int v = a / j;
                y.push_back(j);
                y.push_back(v);
                //cout <<j <<"  "<<v<<endl;
                //pw=v;
            }
            //vec[a]=false;
        }
    };
    sort(A.begin(), A.end());
    //for(int m=0;m<N;m++){
    //    yakusuu(A[m]);
    //}
    ans = N;
    for (int m = 0; m < N; m++)
    {
        if (arr.at(A[m]) == 1)
        {
            vector<int> yk;
            //vec[A[m]] = true;
            yakusuu(A[m], yk);
            for (int k = 0; k < yk.size(); k++)
            {
                if (vec[yk[k]] == true)
                {
                    ans--;
                    vec[A[m]] = true;
                    break;
                }
            }
            vec[A[m]] = true;
        }else{
            vec[A[m]] = true;
            ans--;
        }
        //if(vec[A[m]]==true && arr.at(A[m])==1){
        //    ans++;
        //    cout << A[m]<<endl;
        //}
    }
    cout << ans << endl;
}