#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,K;
    int sum = 0;
    cin >> N >> K;
     vector<int> vec(N);
    for(int i = 0; i < N ; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());

    for(int j = 0; j < K; j++)
    {
        sum = sum+vec[j];
    }
cout << sum << endl;
}