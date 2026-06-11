#include<bits/stdc++.h>
using namespace std;

int ara[2003],tra[2003];
vector<int>vh[2003],vv[2003];
vector<string>vst;

int main()
{

    int n,m,i,j,k,ans=0,cur=0,sz,p,q,r,s,t,fr,sc;
    vector<int>::iterator it;
    string str;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        cin>>str;

        for(j=0;j<m;j++)
        {
            if(str[j]=='#')
            {
                vh[i].push_back(j);  vv[j].push_back(i);
            }

        }

        vst.push_back(str);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cur=0;

            if(vst[i][j]=='.')
            {
                fr=vh[i].size();

                if(fr==0)cur=cur+(m-1);
                else
                {
                    it=upper_bound(vh[i].begin(),vh[i].end(),j); p=it-vh[i].begin();
                    if(p!=fr)q=vh[i][p];
                    else{  q=m;  }
                    r=(q-j)-1; cur=cur+r;
                    p--;
                    if(p>=0)q=vh[i][p];
                    else{  q=-1; }
                    r=(j-q)-1; cur=cur+r;

                }

                fr=vv[j].size();

                if(fr==0)cur=cur+(n-1);
                else
                {
                    it=upper_bound(vv[j].begin(),vv[j].end(),i); p=it-vv[j].begin();
                    if(p!=fr){ q=vv[j][p]; }
                    else{  q=n; }
                    r=(q-j)-1; cur=cur+r;
                    p--;
                    if(p>=0)q=vv[j][p];
                    else{ q=-1;  }
                    r=(j-q)-1; cur=cur+r;

                }

                cur++;

                //cout<<i<<" "<<j<<"        "<<cur<<endl;

                if(cur>ans)ans=cur;

            }

        }
    }

    printf("%d\n",ans);



    return 0;
}
