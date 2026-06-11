#include<bits/stdc++.h>
using namespace std;

vector<long long int > primes;
bool isprime[2000009];
int ndiv[1000009];

void div()
{
    long long int sum=0;
    for(int i=1; sum<=1000000; i++)
    {
        sum+=i;
        ndiv[sum]=i;
    }
    int c =1;
    for(int i=1; i<=1000000; i++)
    {
        if(ndiv[i]==0)
            ndiv[i]=c;
        else
            c=ndiv[i];
    }


}
void sieve()
{
    for(int i=3; i<=2000005; i+=2)
    {
        if(isprime[i]==0)
        {
            for(int j=i*2; j<=2000005; j+=i)
                isprime[j]=1;
        }
    }
    primes.push_back(2);
    for(int i=3; i<2000005; i+=2)
        if(isprime[i]==0)
            primes.push_back(i);
}

int main()
{
   /// sieve();
    ///div();

    long long num;
    map<long long int,long long  int >mp;
    vector<long long int > st;
    while(cin>>num)
    {
      long int  sum =0;
        for(long long int i=2; i*i<=num; i++)
        {
            if(num%i==0)
            {
                int c=0;
                ///st.push_back(i);
                while(num%i==0)
                {
                    c++;
                    num/= i;
                }
                int k=1;
                while(c>=k){
                        c-=k;
                    k++;sum++;
                }
                ///sum+= ndiv[c];
            }
        }
        if(num>1)
        {
            sum++;
        }
        cout<<sum<<endl;
        mp.clear();
        st.clear();
    }

    return 0;
}
