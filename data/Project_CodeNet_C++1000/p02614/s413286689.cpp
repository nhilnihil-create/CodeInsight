        #include <stdio.h>
        #include <math.h> 
        int main(void){
            // Your code here!
            int H,W,K;
            char map[6][7] = {};
            int ans = 0;
            
            scanf("%d%d%d",&H,&W,&K);
            
            for(int i = 0; i < H; i++){
                scanf("%6s",map[i]);
                //printf("%s\n",map[i]);
            }
            
            for(int Hb = 0; Hb < (int)pow(2,H); Hb++ ){
                for(int Wb = 0; Wb < (int)pow(2,W); Wb++){
                    int brack = 0;
                    for(int i = 0; i < H; i++){
                        for(int j = 0; j < W; j++){
                            if((Hb>>i & 1) == 0 && (Wb>>j & 1) == 0 && map[i][j] == '#'){
                                brack++;
                            }
                        }
                    }
                    if(brack == K){
                        ans++;
                    }
                }
            }
            
            printf("%d\n",ans);
        }
