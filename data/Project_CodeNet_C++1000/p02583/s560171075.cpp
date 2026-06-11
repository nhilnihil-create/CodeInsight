#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <assert.h>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    vector<int> v;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    
    int ans = 0;
    for(int i = 0; i < N-2; i++)
    {
        int j = i+1;
        int k = i+2;
        while(j < k && k < N)
        {
            j = k-1;
            while(v[i]+v[j] > v[k] && j > i)
            {
                if(v[i] != v[j] && v[j] != v[k])
                    ans++;
                j--;
            }
            k++;
        }
    }
    cout << ans;
    
}