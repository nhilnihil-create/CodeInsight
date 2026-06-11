    #include<bits/stdc++.h>
    using namespace std;


    int main()
    {
        int n,m,x,val,k;
        cin>>n>>m>>k;

        int ans=123456789;
        std::vector<int> v1[n];
        std::vector<int> cost(12);
        for(int i=0;i<n;i++)
        {
            cin>>cost[i];
            for(int j=0;j<m;j++)
            {
                cin>>val;
                v1[i].push_back(val);
            }
        }

        int maxi=1<<n;

        for(int i=1;i<maxi;i++)
        {
            std::vector<int> v2(m,0);
            int x,ind=0,sum=0;
            x=i;
            while(x)
            {
                int t=x%2;
                if(t==1)
                {
                    for(int j=0;j<m;j++)
                    {
                        v2[j]+=v1[ind][j];
                    }
                    sum+=cost[ind];
                }
                x=x/2;
                ind++;
            }

            int chk=0;
            for(int j=0;j<m;j++)
            {
                if(v2[j]<k)
                    chk++;
            }
            if(chk==0)
            {
                if(ans>sum)
                    ans=sum;
            }
        }

        if(ans==123456789)
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
        return 0;
    }