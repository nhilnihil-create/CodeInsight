    #include<cstdio>
    #include<cstring>

    int main()
    {
        int n,ans=0,m=1;
        int num;
        scanf("%d", &n);
        for (int i = 0; i < n;i++)
        {
            scanf("%d", &num);
            if(num==m)
            {
                m++;
            }
            else
                ans++;
        }
        if(ans==n)
            printf("-1");
        else
            printf("%d",ans);
        return 0;
    }