#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;
long int cnt;
void insertionSort(vector<long int> &vec,long int n,long int g)
{
    for(long int i = g;i < n;i++)
    {
        long int v = vec.at(i);
        long int j = i - g;
        while(j >= 0 && vec.at(j) > v)
        {
            vec.at(j + g) = vec.at(j);
            j = j - g;
            cnt++;
        }
        vec.at(j + g) = v;
    }
}
int main()
{
    long int n;
    cin >> n;
    vector<long int> v;
    for(long int i = 0;i < n;i++)
    {
        long int t;
        cin >> t;
        v.push_back(t);
    }
    cnt = 0;
    int m = 13;
    long int g[13] = {797161,265720,88573,29524,9841,3280,1093,364,121,40,13,4,1};
    int ind = 0;
    for(int i = 0;i < 13;i++)
    {
        if(n >= g[i])
        {
            ind = i;
            break;
        }
    }
    cout << 13 - ind << endl;
    for(int i = ind;i < 13;i++)
    {
        cout << g[i];
        if(i + 1 != 13)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    for(int i = ind;i < m;i++)
    {
        insertionSort(v,n,g[i]);
    }
    cout << cnt << endl;
    for(long int i  = 0;i < n;i++)
    {
        cout << v.at(i) << endl;
    }
}