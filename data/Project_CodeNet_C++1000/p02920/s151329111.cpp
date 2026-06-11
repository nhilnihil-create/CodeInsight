#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int N = pow(2,n);
    vector<int> t(2*N-1);
    multiset<int> st;
    for (int i=0;i<N;i++)
    {
        int s;
        cin>>s;
        st.insert(s);
    }
    t[0]=*st.rbegin();
    st.erase(st.find(t[0]));
    int k = 1;
    for (int i=0;i<N-1;i=2*i+1)
    {
        for (int j=i;j<=2*i;j++)
        {
            t[2*j+1]=t[j];
            multiset<int>::iterator it=st.lower_bound(t[j]);
            if (it==st.begin())
            {
                cout<<"No"<<endl;
                return 0;
            }
            else
            {
                t[2*j+2]=*(--it);
                st.erase(it);
            }
            k++;
        }
    }
    cout << "Yes" << endl;
}
