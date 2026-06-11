#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

int main()
{
    long long int N {};
    cin>>N;
    vector<long long int> xi (N),yi (N);
    signed long long int maxxPlus {LLONG_MIN},minnPlus {LLONG_MAX};
    signed long long int maxxMinus {LLONG_MIN},minnMinus {LLONG_MAX};
    for(int i=0;i<N;i++)
    {
        cin>>xi.at(i)>>yi.at(i);
    }
    long long int posMinPlus {},posMaxPlus {};
    long long int posMinMinus {},posMaxMinus {};
    for(int i=0;i<N;i++)
    {
        if (maxxPlus<(xi.at(i)+yi.at(i)))
        {
            maxxPlus=xi.at(i)+yi.at(i);
            posMaxPlus=i;
        }
        if(minnPlus>(xi.at(i)+yi.at(i)))
        {
            minnPlus=xi.at(i)+yi.at(i);
            posMinPlus=i;
        }


        if (maxxMinus<(xi.at(i)-yi.at(i)))
        {
            maxxMinus=xi.at(i)-yi.at(i);
            posMaxMinus=i;
        }
        if(minnMinus>(xi.at(i)-yi.at(i)))
        {
            minnMinus=xi.at(i)-yi.at(i);
            posMinMinus=i;
        }

    }
    cout<<max((llabs(xi.at(posMaxPlus)-xi.at(posMinPlus))+llabs(yi.at(posMaxPlus)-yi.at(posMinPlus))),
              (llabs(xi.at(posMaxMinus)-xi.at(posMinMinus))+llabs(yi.at(posMaxMinus)-yi.at(posMinMinus))));
    return 0;
}