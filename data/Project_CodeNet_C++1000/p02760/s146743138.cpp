#include<bits/stdc++.h>
using namespace std;
bool visited[3][3];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[3][3];
    memset(visited,sizeof(visited),false);
    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<visited[i][j]<<"w ";
        }
        cout<<"\n";
    }*/
    map<int,int>track;
    map<int,int>row;
    map<int,int>column;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
            track[arr[i][j]]++;
            row[arr[i][j]]=i;
            column[arr[i][j]]=j;

        }
    }
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        //cout<<a<<"\n";
        if(track[a]!=0)
        {
            //cout<<a<<"im here"<<"\n";
            visited[row[a]][column[a]]=true;
        }

    }
    int r,c,d1,d2;
    
    //row check
    for(int i=0;i<3;i++)
    {
        r=0;
        for(int j=0;j<3;j++)
        {
            if(visited[i][j]==true)
            {
                //cout<<i<<" "<<j<<"\n";
            r++;
            }
        }
        if(r==3)
        {
            cout<<"Yes"<<"\n";
            return 0;
        }
    }
    //column check
    for(int i=0;i<3;i++)
    {
        c=0;
        for(int j=0;j<3;j++)
        {
            if(visited[j][i])
            c++;
        }
        if(c==3)
        {
            cout<<"Yes"<<"\n";
            return 0;
        }
    }
    //d1 check
    if (visited[0][0] && visited[1][1] && visited[2][2])
    {
        cout<<"Yes"<<"\n";
        return 0;
    }
    if(visited[0][2] && visited[1][1] && visited[2][0])
    {
        cout<<"Yes"<<"\n";
        return 0;
    }
    cout<<"No"<<"\n";
}